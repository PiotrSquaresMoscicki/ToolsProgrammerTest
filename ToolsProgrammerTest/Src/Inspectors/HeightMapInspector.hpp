#pragma once

#include <QtWidgets/qmenu.h>
#include <QtWidgets/qaction.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>

#include "Inspectors/IInspector.hpp"
#include "Managers/IInspectorManager.hpp"

namespace TPT
{
	class HeightMapInspector : public IInspector, public QWidget
	{
	public:
		HeightMapInspector(QWidget* parent);

		void SetManager(IInspectorManager* manager) override;

	public slots:
		void HeightMapLoaded(const QPixmap* heightMap);

	private:
		IInspectorManager* Manager = nullptr;
		const QPixmap* HeightMap = nullptr;

		QLabel* Image;

		QMenu* ContextMenu;
			QAction* LoadHeightMapAction;

		void resizeEvent(QResizeEvent* e) override;

	private slots:
		void SpawnContextMenu(QPoint pos);
			void LoadHeightMap();
	};
}