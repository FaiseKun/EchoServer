#ifndef GPIO_H
#define GPIO_H

#include <QObject>

const QList<int> LEDS = {18,23,24,25};
const int LFLAGS = 0;
const int CHIP = 0;

class gpio : public QObject
{
    Q_OBJECT
public:
    explicit gpio(QObject *parent = nullptr); //Constructor
    ~gpio(); // Destructor
    void set(int pin,bool value);
    void set(unsigned int pattern);

signals:

public slots:

private:
    int m_handle;
};

#endif // GPIO_H
