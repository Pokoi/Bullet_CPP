/*
 * File: RenderTask.hpp
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

#include <SFML/Window.hpp>
#include <Render_Node.hpp>
#include <RenderComponent.hpp>
#include <Light.hpp>
#include <Camera.hpp>
#include <Window.hpp>

namespace BulletAssignment
{
    class RenderTask
    {
        std::shared_ptr<glt::Render_Node>   renderer;
        std::shared_ptr<glt::Camera>        camera;
        std::shared_ptr<glt::Light>         light;

        Window window;
        
    public:

        RenderTask (
                    std::string window_name,
                    unsigned int width, 
                    unsigned int height
                   ):
                    window{window_name, width, height}                   
                    
        {
            renderer    = std::make_shared<glt::Render_Node>();
            camera      = std::make_shared<glt::Camera>(20.f, 1.f, 50.f, 1.f);
            light       = std::make_shared<glt::Light>();

            renderer->add("camera", camera);
            renderer->add("light", light);

            light->translate(glt::Vector3(0.f, 2.f, -2.f));

        }

        void run()
        {
            renderer->render();
        }

        void add_render_model(std::shared_ptr <RenderComponent>& component)
        {
            renderer->add(component->get_owner()->get_name(), component->get_model());
        }

        std::shared_ptr<glt::Camera> & get_camera()
        {
            return camera;
        }
    };

}
