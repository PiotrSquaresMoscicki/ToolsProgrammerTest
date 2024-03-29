#pragma once

#include "Managers/IProjectManager.hpp"

namespace TPT
{
	class ProjectManager : public IProjectManager
	{
	public:
		void SetInspectorManager(std::unique_ptr<IInspectorManager> inspectorManager) override 
			{ InspectorManager = std::move(inspectorManager); }

		void SetSceneManager(std::unique_ptr<ISceneManager> sceneManager) override 
			{ SceneManager = std::move(sceneManager); }

		void SetCommandsManager(std::unique_ptr<ICommandsManager> commandsManager) override
			{ CommandsManager = std::move(commandsManager); }

		void LoadHeightMap(const QString& path) override;

		virtual ISceneManager* GetSceneManager() override { return SceneManager.get(); }

	private:
		std::unique_ptr<IInspectorManager> InspectorManager;
		std::unique_ptr<ISceneManager> SceneManager;
		std::unique_ptr<ICommandsManager> CommandsManager;
	};
}