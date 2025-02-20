#pragma once

#include "mvItemRegistry.h"

namespace Marvel {

    MV_REGISTER_WIDGET(mvTabButton, MV_ITEM_DESC_DEFAULT, StorageValueTypes::None, 1);
    class mvTabButton : public mvAppItem
    {

    public:

        static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

        MV_APPLY_WIDGET_REGISTRATION(mvAppItemType::mvTabButton, add_tab_button)
        MV_NO_COMMANDS
        MV_DEFAULT_CHILDREN
        MV_NO_CONSTANTS

        MV_START_PARENTS
            MV_ADD_PARENT(mvAppItemType::mvTabBar),
            MV_ADD_PARENT(mvAppItemType::mvStage),
            MV_ADD_PARENT(mvAppItemType::mvTemplateRegistry)
        MV_END_PARENTS


        // TODO: correct these
        MV_SET_STATES(MV_STATE_NONE);

    public:

        explicit mvTabButton(mvUUID uuid);

        void draw(ImDrawList* drawlist, float x, float y) override;
        void handleSpecificKeywordArgs(PyObject* dict) override;
        void getSpecificConfiguration(PyObject* dict) override;
        void applySpecificTemplate(mvAppItem* item) override;

    private:

        ImGuiTabItemFlags _flags = ImGuiTabItemFlags_None;

    };
}
