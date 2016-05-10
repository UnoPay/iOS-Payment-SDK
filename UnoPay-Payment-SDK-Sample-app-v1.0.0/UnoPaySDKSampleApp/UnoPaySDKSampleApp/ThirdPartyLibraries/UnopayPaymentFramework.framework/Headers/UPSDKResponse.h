//
//  UPSDKResponse.h
//  UnopayBuyer
//
//  Created by Aparna on 4/19/16.
//  Copyright © 2016 TechJini Digital Services Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    UPResponseStatusInvalid,
    UPResponseStatusSuccess,
    UPResponseStatusFailure,
    UPResponseStatusCancel,
} UPResponseStatus;


typedef enum : NSUInteger {
    UPResponseErrorInvalidAmount,
    UPResponseErrorInvalidMobileNumber,
    UPResponseErrorTransactionInvalid,
    UPResponseErrorInternetUnAvailable,
    UPResponseErrorUserCancelled,
    UPResponseErrorNone
} UPResponseErrorCode;


static NSString *UPSDKErrorDomain = @"UPSDKErrorDomain";

@interface UPSDKResponse : NSObject

@property(nonatomic, assign)double requestedAmount;
@property(nonatomic, assign)double merchantAmount;
@property(nonatomic, strong)NSString *merchantReferenceId;
@property(nonatomic, strong)NSString *merchantName;
@property(nonatomic, strong)NSString *transactionId;

@property(nonatomic, assign)UPResponseStatus status;
@property(nonatomic, strong)NSError *error;


@end
