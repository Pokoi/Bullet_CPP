/*
 * File: Scene.hpp
 * File Created: 25 May 2020
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

#include <map>
#include <Entity.hpp>
#include <PhysicTask.hpp>
#include <RenderTask.hpp>
#include <OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

namespace BulletAssignment
{

    class Scene
    {
    private:
            
        RenderTask view;
        PhysicTask world;

        std::map<std::string, std::shared_ptr<Entity>> entities;

        bool running = true;

        float aspect_ratio;

    public:

        Scene(
                std::string window_name,
                unsigned int width,
                unsigned int height
            ):
                view {window_name, width, height},
                world{}
        {            
            aspect_ratio = float(width) / float(height);


            //Player creation           
            std::shared_ptr<Entity> player(this, "player");         


        }

        void run()
        {
            float fps = 60.f;

            const sf::Time timeUpdate = sf::seconds(1.0f / fps);
           
            view.get_camera()->set_aspect_ratio(aspect_ratio);
           

            glClearColor(0.4f, 0.5f, 0.2f, 1.f);

            sf::Clock timer;
            auto lastTime = sf::Time::Zero;
            auto nowTime = timer.getElapsedTime();
            auto deltaTime = nowTime - lastTime;
            running = true;

            do {
                nowTime = timer.getElapsedTime();

                input();

                world.run(deltaTime.asSeconds());

                for (auto& entity : entities)
                {
                    entity.second->update(deltaTime.asSeconds());
                }              

                render();

                deltaTime = nowTime - lastTime;
                lastTime = nowTime;


            } while (running);
        }

        void input()
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                running = false;
            }
        }

        void render()
        {
            view.run();
        }

        RenderTask& get_render_task()
        {
            return view;
        }

        PhysicTask& get_physic_task()
        {
            return world;
        }

        std::shared_ptr<Entity>& get_entity(std::string name)
        {
            return entities[name];
        }

        void add_entity(std::string name, std::shared_ptr<Entity> & entity)
        {
            entities[name] = entity;
        }

    };
}