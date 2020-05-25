/*
 * File: Window.hpp
 * File Created: 25th May 2020
 * ––––––––––––––––––––––––
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ––––––––––––––––––––––––
 * MIT License
 *
 * Copyright (c) 2020 Pokoidev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <glad/glad.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

namespace BulletAssignment
{
    class Window
    {
        std::shared_ptr <sf::Window> window;

        unsigned int width;
        unsigned int height;

    public:

        Window(
                std::string name,
                unsigned int width,
                unsigned int height
              ):
                width{width},
                height{height}
        {
            window = std::make_shared<sf::Window>(sf::VideoMode(width, height), name, sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
            gladLoadGL();

            glViewport(0, 0, width, height);
        }

        unsigned int get_width()
        {
            return width;
        }

        unsigned int get_height()
        {
            return height;
        }

        std::shared_ptr <sf::Window>& get_window()
        {
            return window;
        }

        void render()
        {
            window->display();
        }

        void clear()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }     


    };
}