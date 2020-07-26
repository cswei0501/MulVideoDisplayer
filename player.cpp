#include <QTimer>
#include <QDebug>
#include "errorlabel.h"
#include "player.h"

Player::Player(QWidget *parent):
    VideoWidget (parent)
{
    errorL_ = new ErrorLabel(this);
    errorL_->hide();
    connect(this, SIGNAL(sigError(QString)), this, SLOT(slotError(QString)));
    connect(this, SIGNAL(sigVideoStoped()), this, SLOT(slotStoped()));
}

void Player::startPlay(const QString &url, const QString &device)
{
    errorL_->hide();
    VideoWidget::startPlay(url, device);
}

void Player::slotError(QString str)
{
    errorL_->setText(str);
    errorL_->show();
}

void Player::slotStoped()
{
    QTimer::singleShot(5000, this, [&]{
        startPlay(url(), decoderName());
    });
}
