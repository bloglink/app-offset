/*******************************************************************************
 * Copyright [2018] <青岛艾普智能仪器有限公司>
 * All rights reserved.
 *
 * version:     0.1
 * author:      zhaonanlin
 * brief:       KB值计算工具
*******************************************************************************/
#ifndef APPOFFSET_H
#define APPOFFSET_H

#include <QFile>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QLocale>
#include <QLineEdit>
#include <QDateTime>
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>

class AppOffset : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppOffset(QWidget *parent = 0);
    ~AppOffset();
private slots:
    void initUI();
    void initSkin();
    void calck();
    void calcb();
private:
    QLineEdit *II11;
    QLineEdit *II12;
    QLineEdit *II21;
    QLineEdit *II22;
    QLineEdit *KK11;
    QLineEdit *BB11;
    QLineEdit *BB12;
    QLineEdit *BB13;
};

#endif // APPOFFSET_H
