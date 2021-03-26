//
//  YJSizeMacro.m
//  YJMacros
//
//  Created by Jing on 2021/3/26.
//

#import "YJSizeMacro.h"

@implementation YJSizeMacro

+ (instancetype)manager {
    static POSizeMacro * object = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        object = [[POSizeMacro alloc] init];
    });
    return object;
}

- (CGRect)screenBounds {
    return [UIScreen mainScreen].bounds;
}

- (CGFloat)screenWidth {
    return CGRectGetWidth(self.screenBounds);
}

- (CGFloat)screenHeight {
    return CGRectGetHeight(self.screenBounds);
}

- (CGFloat)statusBarHeight {
    if (@available(iOS 13.0, *)) {
        return CGRectGetHeight([UIApplication sharedApplication].windows.firstObject.windowScene.statusBarManager.statusBarFrame);
    }
    
    return CGRectGetHeight([UIApplication sharedApplication].statusBarFrame);
}

- (CGFloat)bottomBarHeight {
    if (self.statusBarHeight > 40) {
        return  34.f;
    }
    return 0;
}

- (CGFloat)navigationBarHeight {
    return self.statusBarHeight + 44.f;
}

- (CGFloat)tabBarHeight {
    return self.bottomBarHeight + 49.f;
}

@end
