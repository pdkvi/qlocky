#include "clock.hpp"

#include <QTimer>

Clock::Clock(QObject* pParent)
    : QObject(pParent),
      m_pTimeoutTimer(new QTimer(this)), m_Counter(0, 0)
{
	connect(m_pTimeoutTimer, &QTimer::timeout, this, &Clock::UpdateTime);
}

void Clock::Start()
{
	if (m_pTimeoutTimer->isActive() == false)
	{
		m_pTimeoutTimer->start(1000);
		emit Started();
	}
}

void Clock::Stop()
{
	if (m_pTimeoutTimer->isActive() == true)
	{
		m_pTimeoutTimer->stop();
		emit Stopped();
	}
}

void Clock::UpdateTime()
{
	m_Counter = m_Counter.addSecs(1);
	emit TimeChanged();
}

void Clock::ResetTime()
{
	m_Counter = QTime(0, 0);
	emit TimeChanged();
}

QTime const& Clock::GetTime() const
{
	return m_Counter;
}

bool Clock::IsActive() const
{
	return m_pTimeoutTimer->isActive();
}
