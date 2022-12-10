#ifndef QLOCKY_CLOCK_HPP
#define QLOCKY_CLOCK_HPP
#pragma once

#include <QObject>
#include <QTime>

QT_FORWARD_DECLARE_CLASS(QTimer)

class Clock : public QObject
{
	Q_OBJECT

public:
	Clock(QObject* pParent = nullptr);
	~Clock() = default;

signals:
	void Started();
	void Stopped();
	void TimeChanged();

public slots:
	void Start();
	void Stop();

	void UpdateTime();
	void ResetTime();

public:
	QTime const& GetTime() const;
	bool IsActive() const;

private:
	QTimer* m_pTimeoutTimer;
	QTime m_Counter;
};


#endif // QLOCKY_CLOCK_HPP
