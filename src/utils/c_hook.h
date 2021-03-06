#ifndef MOHAACCELERATION_C_HOOK_H
#define MOHAACCELERATION_C_HOOK_H

namespace utils {
    class c_hook {
       public:
        auto init() -> bool;
        auto finish() -> bool;

       private:
        auto _add_hook(void* target, void* hook, void** original) -> bool;
    };
    inline c_hook m_hook;
} // namespace utils

#endif //MOHAACCELERATION_C_HOOK_H
