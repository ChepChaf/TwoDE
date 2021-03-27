#include <fmt/format.h>

#include <Vector3.h>

template <>
struct fmt::formatter<TwoDE::Vector3> {
    
    char presentation = 'f';
constexpr auto parse(format_parse_context& ctx) {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

        if (it != end && *it != '}')
            throw format_error("invalid format");

        return it;
    }

    template <typename FormatContext>
    auto format(const TwoDE::Vector3& v, FormatContext& ctx) {
        return format_to(
            ctx.out(),
            presentation == 'f' ? "({:.1f}, {:.1f})" : "({:.1e}, {:.1e})",
            v.x, v.y, v.z);
    }
};