#include "thumbnailer.hpp"

#include <QWebFrame>
#include <QPainter>
#include <QImage>

Thumbnailer::Thumbnailer(const QUrl &url)
{
    page.mainFrame()->load(url);
    connect(&page, SIGNAL(loadFinished(bool)),
            this, SLOT(render()));
}

void Thumbnailer::render()
{
    page.setViewportSize(page.mainFrame()->contentsSize());
    QImage image(page.viewportSize(), QImage::Format_ARGB32);
    QPainter painter(&image);

    page.mainFrame()->render(&painter);
    painter.end();

    QImage thumbnail = image.scaled(400, 400);
    thumbnail.save("thumbnail.png");

    emit finished();
}
