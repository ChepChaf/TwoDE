#include <fmt/format.h>

#include <glm::vec3.h>

template <>
struct fmt::formatter<glm::vec3> {
    
    char presentation = 'f';
constexpr auto parse(format_parse_context& ctx) {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }

    template <typename FormatContext>
    auto format(const glm::vec3& v, FormatContext& ctx) {
        return format_to(
            ctx.out(),
            presentation == 'f' ? "({:.1f}, {:.1f})" : "({:.1e}, {:.1e})",
            v.x, v.y, v.z);
    }
};