#include "SexpRenderer.hpp"

#include <QWebFrame>
#include <QWebElement>
#include <QWebElementCollection>

#include <iostream>

SexpRenderer::SexpRenderer(QNetworkAccessManager* manager, const QUrl &url)
{
    page.setNetworkAccessManager(manager);
    page.mainFrame()->load(url);
    connect(&page, SIGNAL(loadFinished(bool)),
            this, SLOT(render()));
}

void SexpRenderer::render()
{
    QWebElement document = page.currentFrame()->documentElement();
    QWebElementCollection allSpans = document.findAll("span");
    for (auto span : allSpans)
    {
        std::cout << "found span!" << std::endl;
    }
    emit finished();
}
