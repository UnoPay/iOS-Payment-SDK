//
//  UPInAppPayment.h
//  UnopayBuyer
//
//  Created by Aparna on 4/19/16.
//  Copyright © 2016 TechJini Digital Services Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UPSDKRequest.h"
#import "UPSDKResponse.h"

extern NSString *const kPaymentStatusNotification;
extern NSString *const kPaymentStatusNotificationUserInfoKey;

typedef enum : NSUInteger {
    UPEnvironmentTypeDevelopment = 0,
    UPEnvironmentTypeProduction,
} UPEnvironmentType;

@interface UPSDKInAppPaymentManager : NSObject

+ (UPSDKInAppPaymentManager *)sharedInstance;

- (void) initializeWithApiSDKKey:(NSString *)key
                   withPartnerId:(NSString *)partnerId
                     environment:(UPEnvironmentType)environmentType;

- (void) processUrlScheme:(NSURL *)urlScheme;

- (void) initiatePaymentWithRequest:(UPSDKRequest *)request;

- (BOOL) isUnopayAppInstalled;
//- (void)handleCancel;

- (void)postCancel;



@end
