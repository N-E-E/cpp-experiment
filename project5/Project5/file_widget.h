#pragma once

#include <QWidget>
#include "ui_file_widget.h"

class file_widget : public QWidget
{
	Q_OBJECT

public:
	file_widget(QWidget *parent = nullptr);
	~file_widget();

private:
	Ui::file_widgetClass ui;
	// 读取站点信息文件
	void stop_input();
	// 读取路线信息文件
	void line_input();
	// 点击确定查看文件没有问题并且关闭窗口
	void check_file();

};
