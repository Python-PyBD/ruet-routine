#ifndef ROUTINE_H
#define ROUTINE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QColor>
#include <QSettings>
#include <QDesktopWidget>

namespace Ui {
class Routine;
}

class Routine : public QWidget
{
    Q_OBJECT
    
public:
    explicit Routine(QWidget *parent = 0);
    ~Routine();
    void addItem(QString name, QColor textColor, QColor bgColor, int row, int col, int span=1);

private slots:
    void createTable();
    void activateRow(QModelIndex index);
    void activateRow(int row);
    
private:
    Ui::Routine *ui;
    QStandardItemModel *mTableModel;
    QFont mFont;
    QColor cse5012;
    QColor cse503;
    QColor cse505;
    QColor cse5078;
    QColor ee5012;
    QIcon up;
    QIcon ok;
    QIcon down;
};

#endif // ROUTINE_H
