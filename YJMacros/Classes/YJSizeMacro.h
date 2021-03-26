//
//  YJSizeMacro.h
//  YJMacros
//
//  Created by Jing on 2021/3/26.
//

#import <Foundation/Foundation.h>

@interface YJSizeMacro : NSObject

+ (instancetype)manager;

/// 屏幕尺寸 - width
@property (nonatomic, assign, readonly) CGFloat screenWidth;
/// 屏幕尺寸 - heidgt
@property (nonatomic, assign, readonly) CGFloat screenHeight;
/// 屏幕尺寸 - bounds
@property (nonatomic, readonly) CGRect screenBounds;

/// 底部安全区域高度
@property (nonatomic, assign, readonly) CGFloat bottomBarHeight;
/// 导航栏高度（包含电池栏）
@property (nonatomic, assign, readonly) CGFloat navigationBarHeight;
/// tabbar高度（包含底部安全区域）
@property (nonatomic, assign, readonly) CGFloat tabBarHeight;
/// 电池栏高度
@property (nonatomic, assign, readonly) CGFloat statusBarHeight;

@end
