#include "simple2DRenderer.h"


namespace GameEngine {
	namespace Graphics {
		void Simple2DRenderer::submit(const Renderable2D* renderable)
		{
			RenderQueue.push_back(renderable);
		}
		void Simple2DRenderer::flush()
		{
			while (!RenderQueue.empty()) {
				const Renderable2D* renderable = RenderQueue.front();
				
				renderable->getVAO()->bind();
				renderable->getIBO()->bind();


				renderable->getShader().setUniformMat4("ml_matrix", Maths::mat4::translation(renderable->getPosition()));

				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_INT, nullptr);


				renderable->getIBO()->unbind();
				renderable->getVAO()->unbind();

				RenderQueue.pop_front();
			}
		}
	}
}
