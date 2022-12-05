#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include "clock.hpp"

MainWindow::MainWindow(QWidget* pParent)
    : QMainWindow(pParent), m_pUi(new Ui::MainWindow), m_pClock(new Clock(this))
{
	m_pUi->setupUi(this);
	m_pUi->m_pDisplayCounter->display("00:00:00");

	connect(m_pUi->m_pStartButton, &QPushButton::clicked, this, &MainWindow::ManageClock);
	connect(m_pUi->m_pResetButton, &QPushButton::clicked, m_pClock, &Clock::ResetTime);

	connect(m_pClock, &Clock::TimeChanged, this, &MainWindow::RedrawDisplay);
}

void MainWindow::ManageClock()
{
	if (m_pClock->IsActive())
	{
		m_pClock->Stop();
		m_pUi->m_pResetButton->setEnabled(true);
	}
	else
	{
		m_pClock->Start();
		m_pUi->m_pResetButton->setEnabled(false);
	}
}

void MainWindow::RedrawDisplay()
{
	m_pUi->m_pDisplayCounter->display(m_pClock->GetTime().toString("hh:mm:ss"));
}

MainWindow::~MainWindow()
{
	delete m_pUi;
}
