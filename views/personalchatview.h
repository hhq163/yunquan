#ifndef PERSONALCHATVIEW_H
#define PERSONALCHATVIEW_H

#include <QWidget>

namespace Ui {
class personalchatview;
}

class personalchatview : public QWidget
{
    Q_OBJECT

public:
    explicit personalchatview(QWidget *parent = 0);
    ~personalchatview();

private:
    Ui::personalchatview *ui;
};

#endif // PERSONALCHATVIEW_H
