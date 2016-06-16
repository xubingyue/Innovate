//
//  WeChatHandler.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/15.
//
//

#import "WeChatHandler.h"

@implementation WeChatHandler

+(instancetype)sharedManager {
    static dispatch_once_t onceToken;
    static WeChatHandler *instance;
    dispatch_once(&onceToken, ^{
        instance = [[WeChatHandler alloc] init];
    });
    return instance;
}

- (void)dealloc {
    [super dealloc];
}

#pragma mark - WXApiDelegate
- (void)onResp:(BaseResp *)resp {
    //这里去调用SocialUtils中的具体实现接口
//    SocialUtils::wxRespForIos(resp);
    NSLog(@"TTTT");
}

- (void)onReq:(BaseReq *)req {
    NSLog(@"TTTsdfadfaT");
}


@end