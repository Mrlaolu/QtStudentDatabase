#ifndef LOGIN_H
#define LOGIN_H
#include <QMessageBox>
#include <QWidget>

namespace Ui {
class LOGIN;
}

class LOGIN : public QWidget
{
    Q_OBJECT

public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();

private slots:
    void on_btn_login_clicked();
    void on_btn_exit_clicked();

signals:
    void sendLoginSuccess();
    void usernameEntered(const QString &username);

private:
    Ui::LOGIN *ui;
};

#endif // LOGIN_H
