#ifndef FTREEVIEW_H
#define FTREEVIEW_H

#include<QtWidgets/qtreeview.h>
#include<QtWidgets/qfilesystemmodel.h>
#include<QtGui/QMouseEvent>
#include<QtGui/qstandarditemmodel.h>
#include "abfwidget.h" 
#include "txtwidget.h"
#include "fitwidget.h"
#include "autoabf.h"

class FTreeView : public QTreeView {
	Q_OBJECT;
public:
	FTreeView(QWidget* parent);
public slots:
	void open();
	void newtask();
	void renamefile();
	void deletefile();

signals:
	void rootpath(QString fn);
	void showabf(QString fn);
	void doubleClicked();

private:
	QFileSystemModel* model;
	QString filename;

protected:
	void mouseDoubleClickEvent(QMouseEvent* event);
	void contextMenuEvent(QContextMenuEvent* event);
};
#endif // !FTREEVIEW_H
