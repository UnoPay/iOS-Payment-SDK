//
//  UPSDKRequest.h
//  UnopayBuyer
//
//  Created by Aparna on 4/19/16.
//  Copyright © 2016 TechJini Digital Services Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UPSDKRequest : NSObject

@property(nonatomic, strong)NSString *orderId;
@property(nonatomic, assign)double amount;
@property(nonatomic, strong)NSString *mobileNumber;
@property(nonatomic, strong)NSString *email;
@property(nonatomic, strong)NSString *name;
@property(nonatomic, strong)NSString *callbackUrlScheme;


@end
