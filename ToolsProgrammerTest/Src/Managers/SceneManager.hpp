#pragma once

#include "Managers/ISceneManager.hpp"

namespace TPT
{
	class SceneManager : public ISceneManager
	{
	public:
		void SetGeightMap(std::unique_ptr<QImage> heightMap) override { HeightMap = std::move(heightMap); }
		QImage* GetHeightMap() override { return HeightMap.get(); }

		void SetScene(std::unique_ptr<Scene> scene) override { Scene = std::move(scene); }
		Scene* GetScene() override { return Scene.get(); }

		const Point* SpawnPoint() override { Scene->Points.push_back(new Point()); }
		const Point* SpawnPoint(size_t id) override { Scene->Points.push_back(new Point(id)); }
		void DestroyPoint(size_t id) override;

	private:
		std::unique_ptr<QImage> HeightMap;
		std::unique_ptr<Scene> Scene;
	};
}