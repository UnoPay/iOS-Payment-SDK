//
//  ViewController.m
//  UnopaySDKTestApp
//
//  Created by Aparna on 4/20/16.
//  Copyright © 2016 TechJini Digital Services Pvt Ltd. All rights reserved.
//

#import "UPSDKTestViewController.h"
#import <UnopayPaymentFramework/UPSDKInAppPaymentManager.h>

@interface UPSDKTestViewController ()
@property(nonatomic, weak)IBOutlet UITextField *mobileNumber;
@property(nonatomic, weak)IBOutlet UITextField *amount;

@end

@implementation UPSDKTestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.amount.text = @"1";
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:kPaymentStatusNotification object:nil];

    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];

    
    // Dispose of any resources that can be recreated.
}

- (IBAction)payUsingUnopay:(id)sender{
    
    UPSDKRequest *request = [[UPSDKRequest alloc] init];
    request.amount = [self.amount.text doubleValue];
    request.orderId = @"30958345245";
    request.callbackUrlScheme = @"sdktest";
    request.mobileNumber= self.mobileNumber.text;
    
    [[UPSDKInAppPaymentManager sharedInstance]initiatePaymentWithRequest:request];

}

- (void)handleNotification:(NSNotification *)notification{
    
    UPSDKResponse *respnse = notification.userInfo[kPaymentStatusNotificationUserInfoKey];
    NSString *text = nil;
    if(respnse.status == UPResponseStatusSuccess)
    {
        text = [[NSString alloc]initWithFormat:@"Transaction SUCCESSFUL\nTransaction Id: %@\nRequested amount:%1.2f \n Merchant amount  :%1.2f",respnse.transactionId,respnse.requestedAmount,respnse.merchantAmount];
       
        
    }
    else if(respnse.status == UPResponseStatusFailure){
        text = [[NSString alloc]initWithFormat:@"Transaction FAILED \n Transaction Id: %@\n Error message %@",respnse.transactionId,[respnse.error localizedDescription]];
    }
    else if(respnse.status == UPResponseStatusCancel){
        text = [[NSString alloc]initWithFormat:@"Transaction Cancelled \n Transaction Id: %@\n Error message %@",respnse.transactionId,[respnse.error localizedDescription]];
    }

    
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Status" message:text delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil   , nil];
    
    [alertView show];
    
}


@end
