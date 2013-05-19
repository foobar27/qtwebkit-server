#pragma once

#include <QWebPage>

class Thumbnailer : public QObject
{
    Q_OBJECT

public:
    Thumbnailer(const QUrl &url);

signals:
    void finished();

private slots:
    void render();

private:
    QWebPage page;

};
