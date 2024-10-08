#include <cstdlib>
#include <ftxui/dom/table.hpp>

#define CAST_ALIASES
#define IO_ALIASES
#define INC_VECTOR
#include <Types/Types.h>

#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/util/ref.hpp>

#include "TorrentList.h"

static Vector<TorrentEntry> gTorrents = {};

static ftxui::ScreenInteractive* gScreen = nullptr;

static void handleCommand(str& cmd) {
    if (cmd == "quit") {
        gScreen->Exit();
    }

    cmd.clear();
}

int main() {
    using namespace ftxui;

    str command;
    InputOption cmdOpts;
    cmdOpts.multiline = false;
    cmdOpts.on_enter  = [&] {
        handleCommand(command);
        cmdOpts.content = "";
    };
    Component commandInput = Input(&command, "Run \"help\" to see a list of commands", cmdOpts);

    auto paletteComponent = Renderer(commandInput, [&] {
        return vbox({
          hbox(text(" > "), commandInput->Render()) | border,
          text("! This is a status update."),
        });
    });

    auto torrentList = TorrentList();

    auto composition = Container::Vertical({torrentList, paletteComponent});

    auto screen = ScreenInteractive::Fullscreen();
    gScreen     = &screen;
    gScreen->Loop(composition);

    return EXIT_SUCCESS;
}
