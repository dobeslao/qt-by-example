#include "TemplateHandler.h"
#include <QTextEdit>
#include <QListView>
#include <QStringListModel>
#include <QTextCursor>

TemplateHandler::TemplateHandler(QListView *view, QTextEdit *textEdit,
		QObject *parent) : QObject( parent ), mTextEdit( textEdit )
{
	mModel = new QStringListModel(this);
	QStringList templates;
	templates << "<html>" << "</html>" << "<body>" << "</body>";
	mModel->setStringList(templates);
	view->setModel(mModel);
	
	connect(view, SIGNAL(clicked(const QModelIndex&)),
				  SLOT(insertText(const QModelIndex&)));
}

void TemplateHandler::insertText(const QModelIndex& index)
{
	QString text = mModel->data(index, Qt::DisplayRole).toString();
	QTextCursor cursor = mTextEdit->textCursor();
	cursor.insertText(text);
	mTextEdit->setTextCursor(cursor);
}
