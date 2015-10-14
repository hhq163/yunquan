#ifndef ACCOUNTKEEPER_H
#define ACCOUNTKEEPER_H

#include <QObject>
#include <QSettings>
class AccountKeeper : public QObject
{
    Q_OBJECT
public:
    AccountKeeper(QObject *parent = 0);
    ~AccountKeeper();
public:
    int getUserId();
    void setUserId(int userId);

private:
    QSettings *settings;
};
extern AccountKeeper accountKeeper;
#endif // ACCOUNTKEEPER_H
