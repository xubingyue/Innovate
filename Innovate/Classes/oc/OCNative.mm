//
//  OCNative.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/15.
//
//

#include "OCNative.h"
#import "WXApi.h"
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKShareKit/FBSDKShareKit.h>
#import "AppController.h"

#define BUFFER_SIZE 1024 * 100

void OCNative::shareToWeChat()
{
    WXMediaMessage *message = [WXMediaMessage message];
    message.title = @"this is title!";
    message.description = @"descriotion on here!";
    [message setThumbImage:[UIImage imageNamed:@"res1thumb.png"]];
    
    WXWebpageObject *obj = [WXWebpageObject object];
    obj.webpageUrl = @"https://itunes.apple.com/zh/app/dont-bump/id894620968?l=zh&ls=1&mt=8";
    message.mediaObject = obj;
    
    SendMessageToWXReq *req = [[SendMessageToWXReq alloc] init];
    req.bText = NO;
    req.message = message;
    req.scene = WXSceneTimeline;
    [WXApi sendReq:req];
}

void OCNative::shareToFB()
{
    FBSDKShareLinkContent *content = [[FBSDKShareLinkContent alloc] init];
    content.contentURL = [NSURL URLWithString:@"https://developers.facebook.com"];
    [FBSDKShareDialog showFromViewController:[AppController controllerView]
                                 withContent:content
                                    delegate:nil];
}
