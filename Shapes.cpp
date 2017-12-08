//
// Code created by Lisa Dion for CS 120, C++, used with permission
//

#include "Shapes.h"

#include "graphics.h"


/*********** Beginning of Shape class *****************/

Shape::Shape() {
    // default color: black
    fill = {0, 0, 0};
    position = {0, 0};
}

Shape::Shape(color f) : Shape() {
    fill = f;
}

Shape::Shape(point p) : Shape() {
    set_position(p);
}

Shape::Shape(color f, point p) : Shape(f) {
    set_position(p);
}

Shape::Shape(color f, int x_in, int y_in) : Shape(f) {
    set_position(x_in, y_in);
}

Shape::Shape(int x_in, int y_in) : Shape() {
    set_position(x_in, y_in);
}

Shape::Shape(const Shape &s) : fill(s.fill) {
}

Shape::~Shape() {
    // does nothing
}

double Shape::get_area() const {
    return calculate_area();
}

double Shape::get_perimeter() const {
    return calculate_perimeter();
}

color Shape::get_fill() const {
    return fill;
}

point Shape::get_position() const {
    return position;
}

double Shape::get_x() const {
    return position.x;
}

double Shape::get_y() const {
    return position.y;
}

void Shape::set_fill(color f) {
    fill = f;
}

void Shape::set_fill(double r, double g, double b) {
    fill = {r, g, b};
}

void Shape::set_position(point p) {
    position = p;
}

void Shape::set_position(int x_in, int y_in) {
    position = {x_in, y_in};
}

void Shape::move(int delta_x, int delta_y) {
    // Note: if delta_x is negative, this will
    // in effect subtract from the x position.
    position.x += delta_x;
    // Note: if delta_y is negative, this will
    // in effect subtract from the y position.
    position.y += delta_y;
}

/*************** End of Shape class ********************/

/*********** Beginning of Circle class *****************/

Circle::Circle() : Shape(), radius(0) {
}

Circle::Circle(double r) : Shape() {
    set_radius(r);
}

Circle::Circle(double r, color f) : Shape(f) {
    set_radius(r);
}

Circle::Circle(color f) : Shape(f), radius(0) {
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    if (r < 0) {
        radius = 0;
    } else {
        radius = r;
    }
}

void Circle::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    for (double i = 0; i <= 2.0*3.1415926+0.05; i += 2.0*3.1415926/360.0) {
        glVertex2i(position.x+radius*cos(i),position.y+radius*sin(i));
    }
    glEnd();
    /*
    glBegin(GL_TRIANGLE_FAN);
    // center vertex will be white
    glColor3f(1,0,1);
    glVertex2i(position.x, position.y);
    for (double i = 0; i <= 2.0*M_PI+0.05; i += 2.0*M_PI/360.0) {
        // each vertex will be a different color
        glColor3f(fabs(sin(i)), 0.5, fabs(cos(i)));
        glVertex2i(position.x+radius*cos(i),position.y+radius*sin(i));
    }
    glEnd();
     */
}

bool Circle::is_overlapping(const point &p) {
    return is_overlapping(p.x, p.y);
}

bool Circle::is_overlapping(int x, int y) {
    // use Pythagorean Theorem to calculate distance between point and center of circle
    double distance = sqrt((x-position.x)*(x-position.x)+(y-position.y)*(y-position.y));
    // if the distance is <= radius, it overlaps. Otherwise, it doesn't.
    return (distance <= radius);
}

double Circle::calculate_area() const {
    return 3.1415926 * radius * radius;
}

double Circle::calculate_perimeter() const {
    return 2.0 * 3.1415926 * radius;
}

/*************** End of Circle class ********************/

/********** Beginning of Rectangulo class ****************/

Rectangulo::Rectangulo() : Shape(), base(0), height(0) {
}

Rectangulo::Rectangulo(double b, double h) : Shape() {
    // NOT using initializer list with b and h
    // because we want to check for valid input
    // so we call setters instead.
    set_dimensions(b, h);
}

Rectangulo::Rectangulo(double b, double h, color f) : Shape(f) {
    set_dimensions(b, h);
}

Rectangulo::Rectangulo(color f) : Shape(f), base(0), height(0) {
}

Rectangulo::Rectangulo(int x_in, int y_in) : Shape(x_in, y_in), base(0), height(0) {
}

Rectangulo::Rectangulo(point p) : Shape(p), base(0), height(0) {
}

Rectangulo::Rectangulo(double b, double h, color f, int x_in, int y_in) : Shape(f, x_in, y_in) {
    set_dimensions(b, h);
}

void Rectangulo::set_top_left(int x_in, int y_in) {
    if (x_in < 0){
        x_in = 0;
    }
    if (y_in < 0) {
        y_in = 0;
    }
    position = {x_in, y_in};
    // Alternate:
    // position.x = x_in;
    // position.y = y_in;
}

void Rectangulo::set_base(double b) {
    if (b < 0) {
        b = 0;
    }
    base = b;
}

void Rectangulo::set_height(double h) {
    if (h < 0) {
        h = 0;
    }
    height = h;
}

void Rectangulo::set_dimensions(double b, double h) {
    set_base(b);
    set_height(h);
}

void Rectangulo::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left corner
    glVertex2i(position.x, position.y);
    // top right corner
    glVertex2i(position.x + base, position.y);
    // bottom right corner
    glVertex2i(position.x + base, position.y + height);
    // bottom left corner
    glVertex2i(position.x, position.y + height);
    glEnd();
}

bool Rectangulo::is_overlapping(const point &p) {
    // this is not recursive
    // this calls the other is_overlapping method
    return is_overlapping(p.x, p.y);
}

bool Rectangulo::is_overlapping(int x, int y) {
    // check to see if x and y are in range of the Rectangulo
    return (x >= position.x && x <= (position.x + base) &&
            y >= position.y && y <= (position.y + height));
}

double Rectangulo::calculate_area() const {
    return base * height;
}

double Rectangulo::calculate_perimeter() const {
    return 2.0 * base + 2.0 * height;
}

/********** End of Rectangulo class ****************/