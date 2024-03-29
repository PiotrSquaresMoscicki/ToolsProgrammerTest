#include "Pch.hpp"

using namespace TPT;

void DestroyPointCommand::Execute()
{
	InspectorManager->DeselectPoint();
	InspectorManager->PointDestroyedSignal(SceneManager->GetPoint(PointId));
	SceneManager->DestroyPoint(PointId);
}

void DestroyPointCommand::Undo()
{
	SceneManager->SpawnPoint(PointId);
	InspectorManager->PointSpawnedSignal(SceneManager->GetPoint(PointId));
}

void DestroyPointCommand::Redo()
{
	InspectorManager->DeselectPoint();
	InspectorManager->PointDestroyedSignal(SceneManager->GetPoint(PointId));
	SceneManager->DestroyPoint(PointId);
}
