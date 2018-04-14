/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       KB值计算工具
*******************************************************************************/
#include "appoffset.h"

AppOffset::AppOffset(QWidget *parent) : QMainWindow(parent)
{
    initUI();
    initSkin();
}

AppOffset::~AppOffset()
{
}

void AppOffset::initUI()
{
    static const QString strDate = QString(__DATE__).replace("  ", " ");
    static const QDate buildDate = QLocale(QLocale::English).toDate(strDate, "MMM dd yyyy");
    static const QTime buildTime = QTime::fromString(__TIME__, "hh:mm:ss");
    static const QDateTime t(buildDate, buildTime);
    this->setWindowTitle(tr("KB值V-0.1.%1").arg(t.toString("yyMMdd")));

    QStringList strs;
    strs << tr("实际值大:") << tr("实际值小:") << tr("测试值大:") << tr("测试值小:")
         << tr(" ") << tr("计算K值:") << tr(" ")
         << tr("计算b值大:") << tr("计算b值小:") << tr("计算b值平均:");

    QVBoxLayout *llayout = new QVBoxLayout;
    for (int i=0; i < strs.size(); i++) {
        llayout->addWidget(new QLabel(strs.at(i), this));
    }

    QVBoxLayout *rlayout = new QVBoxLayout;

    II11 = new QLineEdit(this);
    rlayout->addWidget(II11);
    II12 = new QLineEdit(this);
    rlayout->addWidget(II12);
    II21 = new QLineEdit(this);
    rlayout->addWidget(II21);
    II22 = new QLineEdit(this);
    rlayout->addWidget(II22);

    QPushButton *btnk = new QPushButton(tr("计算K"), this);
    connect(btnk, SIGNAL(clicked(bool)), this, SLOT(calck()));
    rlayout->addWidget(btnk);

    KK11 = new QLineEdit(this);
    rlayout->addWidget(KK11);

    QPushButton *btnb = new QPushButton(tr("计算b"), this);
    connect(btnb, SIGNAL(clicked(bool)), this, SLOT(calcb()));
    rlayout->addWidget(btnb);

    BB11 = new QLineEdit(this);
    rlayout->addWidget(BB11);
    BB12 = new QLineEdit(this);
    rlayout->addWidget(BB12);
    BB13 = new QLineEdit(this);
    rlayout->addWidget(BB13);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(llayout);
    layout->addLayout(rlayout);

    QFrame *frame = new QFrame(this);
    frame->setLayout(layout);
    this->setCentralWidget(frame);
}

void AppOffset::initSkin()
{
    QFile file;
    QString qss;
    file.setFileName(":/qss_black.css");
    file.open(QFile::ReadOnly);
    qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);
}

void AppOffset::calck()
{
    double i1 = II11->text().toDouble() - II12->text().toDouble();
    double i2 = II21->text().toDouble() - II22->text().toDouble();
    double kk = i1/i2;

    KK11->setText(QString::number(kk));
}

void AppOffset::calcb()
{
    double b1 = II11->text().toDouble() - II21->text().toDouble()*KK11->text().toDouble();
    double b2 = II12->text().toDouble() - II22->text().toDouble()*KK11->text().toDouble();

    BB11->setText(QString::number(b1));
    BB12->setText(QString::number(b2));
    BB13->setText(QString::number((b1+b2)/2));
}
