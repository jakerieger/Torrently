#pragma once

#define IO_ALIASES
#define INC_VECTOR
#include <Types/Types.h>

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

struct TorrentEntry {
    u64 id;  // TODO: Generate a unique identifier during construction
    str name;
    size_t size;
    Path location;

    TorrentEntry(const str& name, size_t size, const Path& location)
        : id(0), name(name), size(size), location(location) {}
};

static ftxui::Component TorrentList() {
    using namespace ftxui;

    class Impl : public ComponentBase {
    private:
        f32 scrollX = 0.1;
        f32 scrollY = 0.1;

    public:
        Impl() {
            auto content = Renderer([=] {
                const auto header = hbox({
                  text("Name") | flex,
                  text("Size") | flex,
                  text("Status") | flex,
                  text("D/L") | flex,
                  text("U/L") | flex,
                  text("Elapsed") | flex,
                });

                return vbox({
                  header,
                });
            });

            Add(Container::Vertical({
                  content,
                }) |
                flex);
        }
    };

    return Make<Impl>();
}
