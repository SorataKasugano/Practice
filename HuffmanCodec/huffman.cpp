#include "huffman.h"

Huffman::Huffman(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.button_statistics, &QPushButton::clicked, this, &Huffman::get_statistics);
	connect(ui.button_codec, &QPushButton::clicked, this, &Huffman::get_codec_table);
	connect(ui.button_transcode, &QPushButton::clicked, this, &Huffman::get_transcoded);
}

Huffman::~Huffman()
{
	Node::free_node(root_);
}

void Huffman::traversal(Node* node, QString code)
{// node cannot be nullptr
	if (node->left || node->right)
	{
		if (node->left) traversal(node->left, code + '0');
		if (node->right) traversal(node->right, code + '1');
	}
	else
	{
		codec_[node->ch] = code;
		ui.text_codec->append(QString("%1: %2").arg(node->ch).arg(code));
	}
}

void Huffman::get_statistics()
{
	input_.clear();
	statistics_.clear();
	ui.text_statistics->clear();
	if ((input_ = ui.text_input->toPlainText()).isEmpty()) return;

	QMap<QChar, int> statistics;
	for (auto ch : input_) statistics[ch]++;
	for (auto iter = statistics.begin();iter != statistics.end();iter++)
	{
		ui.text_statistics->append(QString("%1: %2").arg(iter.key()).arg(iter.value()));
		statistics_.insert(iter.value(), new Node(iter.key(), iter.value()));
	}
}

void Huffman::get_codec_table()
{
	Node::free_node(root_);
	ui.text_codec->clear();
	if (statistics_.empty()) return;

	while (statistics_.size() > 1)
	{
		auto left = statistics_.begin(), right = left + 1;
		Node* parent = new Node(left.key() + right.key());
		parent->left = left.value();
		parent->right = right.value();
		statistics_.remove(statistics_.begin().key(), statistics_.begin().value());
		statistics_.remove(statistics_.begin().key(), statistics_.begin().value());
		statistics_.insert(parent->count, parent);
	}
	root_ = statistics_.begin().value();
	statistics_.clear();

	if (root_) traversal(root_);
}

void Huffman::get_transcoded()
{
	if (!root_ || codec_.empty()) return;
	QString display;
	if (ui.button_transcode->text() == "Transcode: Encode")
	{
		for (auto ch : input_)
		{
			display.append(codec_[ch]);
		}
		ui.button_transcode->setText("Transcode: Decode");
	}
	else 
	{
		Node* cursor = root_;
		for (auto ch : ui.text_output->toPlainText())
		{
			cursor = (ch == '0' ? cursor->left : cursor->right);
			if (!cursor->ch.isNull())
			{
				display.append(cursor->ch);
				cursor = root_;
			}
		}
		ui.button_transcode->setText("Transcode: Encode");
	}
	ui.text_output->setText(display);
}
