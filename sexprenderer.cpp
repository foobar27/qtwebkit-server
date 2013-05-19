#include "sexprenderer.hpp"

#include <QWebFrame>
#include <QWebElement>
#include <QWebElementCollection>

#include <iostream>

SexpRenderer::SexpRenderer(const QUrl &url)
{
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
