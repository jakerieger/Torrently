#pragma once

#include <ftxui/dom/elements.hpp>
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
                  text("Name"),
                  text("Size"),
                  text("Status") | flex,
                  text("D/L"),
                  text("U/L"),
                  text("Elapsed"),
                });

                Vector<Element> torrents = {
                  hbox({
                    text("Adobe Photoshop 2024.1 [R2R]"),
                    text("1.68 GB"),
                    gauge(0.45) | flex,
                    text("54 Mbps"),
                    text("21 Mbps"),
                    text("00:12:34"),
                  }),
                };

                return vbox({
                  header,
                  vbox(torrents),
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
