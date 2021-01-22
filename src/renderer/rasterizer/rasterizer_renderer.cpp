#include "rasterizer_renderer.h"

#include "utils/resource_utils.h"


void cg::renderer::rasterization_renderer::init()
{
	model = std::make_shared<cg::world::model>();
	model->load_obj(settings->model_path);
	auto render_target = std::make_shared<cg::resource<cg::unsigned_color>>(settings->width, settings->height);

	auto rasterizer = std::make_shared<cg::renderer::rasterizer<cg::vertex, cg::unsigned_color>>();
	rasterizer->set_render_target(render_target);
	rasterizer->set_vertex_buffer(model->get_per_shape_buffer());
	
}

void cg::renderer::rasterization_renderer::destroy() {}

void cg::renderer::rasterization_renderer::update() {}

void cg::renderer::rasterization_renderer::render()
{
	
	rasterizer->clear_render_target({ 255, 255, 0 });
	cg::utils::save_resource(*render_target, settings->result_path);
}