//
//  GQDataController.h
//  GQDataContrller
//
//  Created by 钱国强 on 12-12-9.
//  Copyright (c) 2012年 gonefish@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define GQAppVersion @"gq_app_version"
#define GQDeviceMode @"gq_device_model"
#define GQDeviceVersion @"gq_device_version"
#define GQUserInterfaceIdiom @"gq_user_interface_idiom"
#define GQUserLanguage @"gq_user_language"


typedef enum {
    GQResponseDataTypeJSON,
    GQResponseDataTypePLIST,
    GQResponseDataTypeXML
} GQResponseDataType;

@protocol GQDataControllerDelegate;

@interface GQDataController : NSObject

/** Signleton method.
 
*/
+ (id)sharedDataController;

/** Request URL String.
 
 @param urlString a URL String.
*/
+ (void)requestWithURLString:(NSString *)urlString;

- (void)requestWithArgs:(NSDictionary *)args;

- (id)valueForKey:(NSString *)key;
- (id)valueForKeyPath:(NSString *)keyPath;


@property (nonatomic, weak) id<GQDataControllerDelegate> delegate;
@property (nonatomic, assign, readonly) NSInteger retryIndex;
@property (nonatomic, strong, readonly) NSDictionary *requestArgs;

@end

@protocol GQDataControllerDelegate <NSObject>
@optional
// 数据请求成功
- (void)loadingDataFinished:(GQDataController *)controller;

// 数据请求失败
- (void)loadingData:(GQDataController *)controller failedWithError:(NSError *)error;

@end