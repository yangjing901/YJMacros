//
//  YJMacros.h
//  YJMacros
//
//  Created by 杨警 on 2020/12/14.
//

#ifndef YJMacros_h
#define YJMacros_h

//MARK: - 屏幕尺寸
#define yjScreenWidth            CGRectGetWidth(yjScreenBounds)
#define yjScreenHeight           CGRectGetHeight(yjScreenBounds)
#define yjScreenBounds           [UIScreen mainScreen].bounds

#define yjNavigationBarHeight       (yjiPhoneXStyle ? 88.f : 64.f)
#define yjStatusBarHeight           (yjiPhoneXStyle ? 44.f : 20.f)
#define yjBottomBarHeight           (yjiPhoneXStyle ? 34.f : 0.f)
#define yjTabBarHeight              (yjiPhoneXStyle ? 83.f : 49.f)

#define yjWidthScale(width)             ((width)*(yjScreenWidth/375.f))
#define yjWidthScaleX(width)             ((width)*(yjScreenWidth/414.f))

#define yjHeightScale(height)           (yjiPhoneXStyle ? height : (height)*(yjScreenHeight/667.f))
#define yjHeightScaleX(height)           ((height)*((yjScreenHeight-yjStatusBarHeight-yjBottomBarHeight)/(896.f-yjStatusBarHeight-yjBottomBarHeight)))

/// IPhoneX系列
/// 手机开热点情况下非全面屏手机statusBarFrame会变成40(横屏会有问题？)
#define yjiPhoneXStyle ([[UIApplication sharedApplication] statusBarFrame].size.height > 40)

//MARK: - weakify strongify
#ifndef yjWeakify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define yjWeakify(object) autoreleaseyjol{} __weak __typeof__(object) weak##_##object = object;
        #else
            #define yjWeakify(object) autoreleaseyjol{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define yjWeakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
            #define yjWeakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef yjStrongify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define yjStrongify(object) autoreleaseyjol{} __typeof__(object) object = weak##_##object;
        #else
            #define yjStrongify(object) autoreleaseyjol{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define yjStrongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
            #define yjStrongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif


#endif /* YJMacros_h */
