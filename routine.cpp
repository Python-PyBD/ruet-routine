#include "routine.h"
#include "ui_routine.h"

Routine::Routine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Routine)
{
    mTableModel = new QStandardItemModel(this);
    mFont = QFont("Bitstream Vera Sans", 12);

    up = QIcon(":/up");
    ok = QIcon(":/ok");
    down = QIcon(":/down");

    cse5012 = QColor(0, 174, 0);
    cse503 = QColor(255, 255, 0);
    cse505 = QColor(153, 102, 204);
    cse5078 = QColor(255, 51, 51);
    ee5012 = QColor(0,153,255);

    ui->setupUi(this);

    createTable();

    connect(ui->buttons, SIGNAL(rejected()), this, SLOT(close()));
    connect(ui->table, SIGNAL(clicked(QModelIndex)), this, SLOT(activateRow(QModelIndex)));

    setWindowTitle("Third Year Fifth Semester Routine");
    setWindowIcon(QIcon(":/icon"));

    QSettings appSetting("minhazulhaque", "CSE-Routine");
    activateRow(appSetting.value("activeRow", 0).toInt());

    setGeometry(QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    size(),
                    qApp->desktop()->availableGeometry()));
}

Routine::~Routine()
{
    delete ui;
}

void Routine::createTable()
{
    mTableModel->setColumnCount(9);
    mTableModel->setRowCount(5);

    QStringList times;
    times << "8:00"
          << "8:50"
          << "9:40"
          << "10:50"
          << "11:40"
          << "12:30"
          << "2:30"
          << "3:20"
          << "4:10";

    QStringList days;
    days << "A"
         << "B"
         << "C"
         << "D"
         << "E";

    mTableModel->setHorizontalHeaderLabels(times);
    mTableModel->setVerticalHeaderLabels(days);

    addItem("EEE 503", Qt::white, ee5012, 0, 1);
    addItem("CSE 505", Qt::white, cse505, 0, 2);
    addItem("CSE 502", Qt::white, cse5012, 0, 3, 3);
    addItem("EEE 504", Qt::white, ee5012, 0, 6, 3);

    addItem("CSE 507", Qt::white, cse5078, 1, 2);
    addItem("CSE 508", Qt::white, cse5078, 1, 3, 3);
    addItem("CSE 502", Qt::white, Qt::gray /*cse5012*/, 1, 6, 3);

    addItem("CSE 507", Qt::white, cse5078, 2, 2);
    addItem("CSE 505", Qt::white, cse505, 2, 3);
    addItem("CSE 503", Qt::black, cse503, 2, 4);
    addItem("CSE 501", Qt::white, cse5012, 2, 6, 2);

    addItem("CSE 503", Qt::black, cse503, 3, 1);
    addItem("CSE 507", Qt::white, cse5078, 3, 2);
    addItem("CSE 508", Qt::white, Qt::gray /*cse5078*/, 3, 3, 3);

    addItem("EEE 503", Qt::white, ee5012, 4, 0);
    addItem("CSE 503", Qt::black, cse503, 4, 1);
    addItem("CSE 505", Qt::white, cse505, 4, 2);
    addItem("CSE 501", Qt::white, cse5012, 4, 3, 2);

    ui->table->setModel(mTableModel);
    ui->table->setFont(mFont);
    ui->table->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->table->verticalHeader()->setResizeMode(QHeaderView::Stretch);
}

void Routine::activateRow(QModelIndex index)
{
    activateRow(index.row());
}

void Routine::activateRow(int row)
{
    for(int i=0;i<row;i++)
        mTableModel->verticalHeaderItem(i)->setIcon(up);

    mTableModel->verticalHeaderItem(row)->setIcon(ok);

    for(int i=row+1;i<5;i++)
        mTableModel->verticalHeaderItem(i)->setIcon(down);

    QSettings appSetting("minhazulhaque", "CSE-Routine");
    appSetting.setValue("activeRow", row);
}

void Routine::addItem(QString name, QColor textColor, QColor bgColor, int row, int col, int span)
{
    QStandardItem *newClass = new QStandardItem(name);

    newClass->setTextAlignment(Qt::AlignCenter);
    newClass->setBackground(QBrush(bgColor));
    newClass->setData(textColor, Qt::TextColorRole);

    mTableModel->setItem(row, col, newClass);

    if(span!=1)
        ui->table->setSpan(row, col, 1, span);
}
