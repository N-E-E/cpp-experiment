#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Project5.h"

class Project5 : public QMainWindow
{
    Q_OBJECT

public:
    Project5(QWidget *parent = nullptr);
    ~Project5();

private:
    Ui::Project5Class ui;
    // ���ص�ͼ
    void load_map();
    // �رմ���
    void close_window();
    // ������Сת��
    void min_convert();
    // ������̾���
    void min_dist();
};
