#include "mvActiveHandler.h"
#include "mvLog.h"
#include "mvItemRegistry.h"
#include "mvPythonExceptions.h"
#include "mvUtilities.h"

namespace Marvel {

    void mvActiveHandler::InsertParser(std::map<std::string, mvPythonParser>* parsers)
    {
        std::vector<mvPythonDataElement> args;

        AddCommonArgs(args,(CommonParserArgs)(
            MV_PARSER_ARG_ID |
            MV_PARSER_ARG_SHOW |
            MV_PARSER_ARG_PARENT |
            MV_PARSER_ARG_CALLBACK)
        );

        mvPythonParserSetup setup;
        setup.about = "Adds a active handler.";
        setup.category = { "Widgets", "Events" };
        setup.returnType = mvPyDataType::UUID;

        mvPythonParser parser = FinalizeParser(setup, args);

        parsers->insert({ s_command, parser });
    }

    mvActiveHandler::mvActiveHandler(mvUUID uuid)
        :
        mvAppItem(uuid)
    {

    }

    void mvActiveHandler::customAction(void* data)
    {

        mvAppItemState* state = static_cast<mvAppItemState*>(data);
        if (state->active)
        {
            mvSubmitCallback([=]()
                {
                    if (_alias.empty())
                        mvRunCallback(getCallback(false), _uuid, ToPyUUID(state->parent), _user_data);
                    else
                        mvRunCallback(getCallback(false), _alias, ToPyUUID(state->parent), _user_data);
                });
        }
    }
}
