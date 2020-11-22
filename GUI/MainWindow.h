#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QTableWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void setWidthForTable(QTableWidget *table, int width);

private:
    Ui::Widget *ui;
    const int m_column_width = 30;
};
#endif // WIDGET_H
