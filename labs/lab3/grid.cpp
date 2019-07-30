#include "grid.h"
#include "const.h"
#include "point.h"
#include "tile.h"
#include <iostream>
#include <iomanip>

using namespace std;

Grid::Grid(unsigned int height, unsigned int width) : height(height), width(width), squares() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            squares[i][j] = nullptr;
        }
    }
}

unsigned int Grid::getHeight() const {
    return height;
}

unsigned int Grid::getWidth() const {
    return width;
}

bool Grid::insideGrid(const Point &pt) const {
    return pt.r >= 0 && pt.r < height && pt.c >= 0 && pt.c < width;
}

Tile *Grid::getSquare(const Point &pt) const {
    return squares[pt.r][pt.c];
}

void Grid::setSquare(const Point &pt, Tile *tile) {
    squares[pt.r][pt.c] = tile;
}

void Grid::clearSquare(const Point &pt) {
    setSquare(pt, nullptr);
}

void Grid::clearSquares() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            clearSquare({i, j});
        }
    }
}

bool Grid::isEmpty(const Point &pt) const {
    return getSquare(pt) == nullptr;
}

void Grid::upgradeTile(const Point &pt) {
    squares[pt.r][pt.c]++;
}

static Point getIterationBase(Direction dir, unsigned int height, unsigned int width) {
    Point base;
    switch (dir) {
        case UP:
            base = {0, 0};
            break;
        case DOWN:
            base = {(int) height - 1, (int) width - 1};
            break;
        case LEFT:
            base = {(int) height - 1, 0};
            break;
        case RIGHT:
            base = {0, (int) width - 1};
            break;
    }
    return base;
}

unsigned int Grid::collapseTiles(Direction dir) {
    unsigned int points = 0;
    Point base = getIterationBase(dir, height, width);
    Direction nextBase = rotateClockwise(dir);
    Direction nextTarget = opposite(dir);
    while (insideGrid(base)) {
        Point dst = base, src = base;
        while (insideGrid(src)) {
            if (!isEmpty(src)) {
                if (!isEmpty(dst) && dst != src && getSquare(dst) == getSquare(src)) {
                    clearSquare(src);
                    upgradeTile(dst);
                    points += getSquare(dst)->points;
                    dst = adjacentPoint(dst, nextTarget);
                } else {
                    dst = src;
                }
            }
            src = adjacentPoint(src, nextTarget);
        }
        base = adjacentPoint(base, nextBase);
    }
    return points;
}

bool Grid::shiftTile(const Point &dst, const Point &src) {
    if (!isEmpty(dst) || isEmpty(src)) {
        return false;
    } else {
        setSquare(dst, getSquare(src));
        clearSquare(src);
        return true;
    }
}

bool Grid::shiftTiles(Direction dir) {
    bool shifted = false;
    Point base = getIterationBase(dir, height, width);
    Direction nextBase = rotateClockwise(dir);
    Direction nextTarget = opposite(dir);
    while (insideGrid(base)) {
        Point dst = base, src = base;
        while (insideGrid(src)) {
            if (!isEmpty(src)) {
                if (shiftTile(dst, src)) {
                    shifted = true;
                }
                dst = adjacentPoint(dst, nextTarget);
            }
            src = adjacentPoint(src, nextTarget);
        }
        base = adjacentPoint(base, nextBase);
    }
    return shifted;
}

void Grid::printGrid() const {
    for (int i = 0; i < height; i++) {
        wcout << "|";
        for (int j = 0; j < width; j++) {
            if (isEmpty({i, j})) {
                wcout << setw(TILEWIDTH) << " " << "\t";
            } else {
                squares[i][j]->printTile();
            }
            wcout << "|";
        }
        wcout << endl << endl;
    }
}
