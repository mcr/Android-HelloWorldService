/*
 * These are repeats of macros found in utils/IInterface.h.
 * the version there, does not use the proper namespace, so you have
 * to write them in "android" namespace.
 */

#define android_DECLARE_META_INTERFACE(INTERFACE)                               \
        static const android::String16 descriptor;                      \
        static android::sp<I##INTERFACE> asInterface(const android::sp<android::IBinder>& obj); \
        static android::String16 getInterfaceDescriptor();              \

#define android_IMPLEMENT_META_INTERFACE(INTERFACE, NAME)                       \
        const android::String16 I##INTERFACE::descriptor(NAME);         \
        android::String16 I##INTERFACE::getInterfaceDescriptor() { \
        return I##INTERFACE::descriptor;                                \
    }                                                                   \
        android::sp<I##INTERFACE> I##INTERFACE::asInterface(const android::sp<android::IBinder>& obj) \
    {                                                                   \
            android::sp<I##INTERFACE> intr;                             \
        if (obj != NULL) {                                              \
            intr = static_cast<I##INTERFACE*>(                          \
                obj->queryLocalInterface(                               \
                        I##INTERFACE::descriptor).get());               \
            if (intr == NULL) {                                         \
                intr = new Bp##INTERFACE(obj);                          \
            }                                                           \
        }                                                               \
        return intr;                                                    \
    }                                                                   \

