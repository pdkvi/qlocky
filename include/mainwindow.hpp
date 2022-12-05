#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Clock;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

public slots:
	void ManageClock();
	void RedrawDisplay();

private:
	Ui::MainWindow* m_pUi;
	Clock* m_pClock;
};
#endif // MAINWINDOW_HPP
