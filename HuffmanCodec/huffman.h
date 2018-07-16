#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <QtWidgets/QMainWindow>
#include "ui_huffman.h"

#include <QMap>

struct Node
{
	QChar ch;
	int count;
	Node* left;
	Node* right;

	Node(int y) :count(y), left(nullptr), right(nullptr) {}
	Node(QChar x, int y) :ch(x), count(y), left(nullptr), right(nullptr) {}

	static void free_node(Node* node) {
		if (node)
		{
			free_node(node->left);
			free_node(node->right);
			delete node;
		}
	}
};

class Huffman : public QMainWindow
{
	Q_OBJECT

public:
	Huffman(QWidget *parent = 0);
	~Huffman();
	
	void traversal(Node* node, QString code = "");

public slots:
	void get_statistics();
	void get_codec_table();
	void get_transcoded();

private:
	Ui::HuffmanClass ui;

	QString input_;
	QMultiMap<int, Node*> statistics_;
	QHash<QChar, QString> codec_;
	Node* root_ = nullptr;
};

#endif // HUFFMAN_H
