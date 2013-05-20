#pragma once

#include <QNetworkAccessManager>
#include <QWebPage>

class SexpRenderer : public QObject
{
    Q_OBJECT

public:
    SexpRenderer(QNetworkAccessManager *manager, const QUrl &url);

signals:
    void finished();

private slots:
    void render();

private:
    QWebPage page;

};
