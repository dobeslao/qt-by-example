#ifndef MYWIDGET_H_
#define MYWIDGET_H_

#include <QWidget>
#include <QVBoxLayout>

class MyWidget : public QWidget {
	Q_OBJECT
	
public:
	MyWidget (QWidget *parent = 0);
};

#endif /*MYWIDGET_H_*/
